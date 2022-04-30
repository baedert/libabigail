libabigail_sources = files([
  'abg-comp-filter.cc',
  'abg-comparison.cc',
  'abg-config.cc',
  'abg-corpus.cc',
  'abg-default-reporter.cc',
  'abg-diff-utils.cc',
  'abg-dwarf-reader.cc',
  'abg-elf-helpers.cc',
  'abg-elf-reader-common.cc',
  'abg-hash.cc',
  'abg-ini.cc',
  'abg-ir.cc',
  'abg-leaf-reporter.cc',
  'abg-libxml-utils.cc',
  'abg-reader.cc',
  'abg-regex.cc',
  'abg-reporter-priv.cc',
  'abg-suppression.cc',
  'abg-symtab-reader.cc',
  'abg-tools-utils.cc',
  'abg-traverse.cc',
  'abg-workers.cc',
  'abg-writer.cc',

  # VIZ
  'abg-viz-common.cc',
  'abg-viz-dot.cc',
  'abg-viz-svg.cc',
])

libabigail_deps = [
  dependency('libxml-2.0'),
  cxx.find_library('elf'),
  cxx.find_library('dw'),
]

if ctf_enabled
  libabigail_sources += 'abg-ctf-reader.cc'
  libabigail_deps += cxx.find_library('ctf')
endif

libabigail = library(
  'abigail',
  libabigail_sources,
  dependencies: libabigail_deps,
  cpp_args: [
    '-DABIGAIL_ROOT_SYSTEM_LIBDIR="' + get_option('libdir') + '"',
    visibility_cflags,
  ],
  link_args: [
    '-lpthread', '-Wl,--as-needed', '-Wl,--no-undefined'
  ],
  include_directories: [
    toplevel_incdir,
    include_incdir,
  ]
)

libabigail_dep = declare_dependency(
  link_with: libabigail,
  include_directories: [
    include_incdir,
    include_directories('.')
  ]
)
