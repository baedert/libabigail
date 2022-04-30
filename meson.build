project('libabigail',
        'cpp',
        version: '2.1',
)
version_major = meson.project_version().split('.')[0]
version_minor = meson.project_version().split('.')[1]

cxx = meson.get_compiler('cpp')

# Check for visibility attribute compiler support
supports_gcc_visibility_attribute = false
visibility_cflags = []
visibility_test = '''
struct __attribute__((visibility("hidden"))) Foo
{
  int m0;
  Foo() : m0() {}
};
'''
if cxx.compiles(visibility_test)
  visibility_cflags = ['-fvisibility=hidden']
  supports_gcc_visibility_attribute = true
endif

# Configure toplevel config.h
cdata = configuration_data()
headers = [
  'dlfcn.h',
  'inttypes.h',
  'minix/config.h',
  'stdint.h',
  'stdio.h',
  'stdlib.h',
  'strings.h',
  'string.h',
  'sys/stat.h',
  'sys/types.h',
  'unistd.h',
  'wchar.h',
]
foreach header : headers
  cdata.set10('HAS_' + header.underscorify().to_upper(), cxx.has_header(header))
endforeach

dwarf_forms = ['line_strp', 'strx', 'strx1', 'strx2', 'strx3', 'strx4']
foreach form : dwarf_forms
  cdata.set10('HAVE_DW_FORM_' + form, cxx.has_header_symbol('dwarf.h', 'DW_FORM_' + form))
endforeach

dwarf_langs = ['C11', 'C_plus_plus_03', 'C_plus_plus_11', 'C_plus_plus_14', 'D', 'Go',
               'Mips_Assembler', 'Python', 'Rust', 'UPC']
foreach lang : dwarf_langs
  cdata.set10('HAVE_DW_LANG_' + lang + 'enumerator',
              cxx.has_header_symbol('dwarf.h', 'DW_LANG_' + lang))
endforeach


cdata.set10('HAS_GCC_VISIBILITY_ATTRIBUTE', supports_gcc_visibility_attribute)
configure_file(
  output: 'config.h',
  configuration: cdata
)

# User options
ctf_enabled = get_option('ctf')

# Include directories
toplevel_incdir = include_directories('.')
include_incdir = include_directories('include/')

subdir('include')
subdir('src')
subdir('tools')
subdir('tests')


# Print summary
summary('Prefix', get_option('prefix'), section: 'General')
summary('GCC Visibility attribute supported', supports_gcc_visibility_attribute, section: 'General')

summary('CTF', ctf_enabled, section: 'User Options')
