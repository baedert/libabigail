
# Libraries used for testing
testutils = library(
  'testutils',
  'test-utils.cc',
  cpp_args: [
    '-DABIGAIL_SRC_DIR="' + meson.current_source_dir() + '/.."',
    '-DABIGAIL_BUILD_DIR="' + meson.current_build_dir() + '/.."',
  ],
  include_directories: [ toplevel_incdir ]
)
testutils_dep = declare_dependency(
  link_with: testutils,
  include_directories: [ include_directories('.'), toplevel_incdir ]
)

testreadcommon = library(
  'testreadcommon',
  'test-read-common.cc',
  cpp_args: [
    '-DABIGAIL_SRC_DIR="' + meson.current_source_dir() + '/.."',
    '-DABIGAIL_BUILD_DIR="' + meson.current_build_dir() + '/.."',
  ],
  dependencies: [
    libabigail_dep,
    testutils_dep,
  ],
  include_directories: [ toplevel_incdir ]
)
testreadcommon_dep = declare_dependency(
  link_with: testreadcommon,
  include_directories: [ include_directories('.'), toplevel_incdir ]
)

libcatch = library(
  'catch',
  'lib/catch.cc',
)
libcatch_dep = declare_dependency(
  link_with: libcatch,
)


fast_tests = [
  # Name                     DEPENDENCIES    LDFLAGS
  ['test-abidiff',           [],             [] ],
  ['test-abidiff-exit',      [],             [] ],
  ['test-alt-dwarf-file',    [],             [] ],
  ['test-core-diff',         [],             [] ],
  ['test-cxx-compat',        [libcatch_dep], [] ],
  ['test-diff-dwarf',        [],             [] ],
  ['test-diff-dwarf-abixml', [],             [] ],
  #  ['test-elf-helpers', [], [] ],
  ['test-ini',               [],             [] ],
  ['test-kmi-whitelist',     [libcatch_dep], [] ],
  ['test-lookup-syms',       [],             [] ],
  ['test-read-write',        [],             [] ],
  ['test-symtab',            [libcatch_dep], [] ],
  ['test-symtab-reader',     [libcatch_dep], [] ],
  ['test-tools-utils',       [],             [] ],
  ['test-svg',               [],             [] ],
]


foreach t : fast_tests
  name = t[0]
  deps = t[1]
  ldflags = t[2]
  exe = executable(
    name, name + '.cc',
    dependencies: [
      testutils_dep,
      libabigail_dep,
    ] + deps,
    link_args: ldflags,
  )
  test(name, exe, timeout: 10, suite: 'fast')
endforeach


slow_tests = [
  # Name                   DEPENDENCIES          LDFLAGS
  ['test-diff-suppr',      [],                   [] ],
  ['test-types-stability', [],                   [] ],
  ['test-diff-pkg',        [],                   [] ],
  ['test-annotate',        [],                   [] ],
  ['test-diff-filter',     [],                   [] ],
  ['test-read-dwarf',      [testreadcommon_dep], ['-pthread'] ],
]

foreach t : slow_tests
  name = t[0]
  deps = t[1]
  ldflags = t[2]
  exe = executable(
    name, name + '.cc',
    dependencies: [
      testutils_dep,
      libabigail_dep,
    ] + deps,
    link_args: ldflags,
  )
  test(name, exe, timeout: 120, suite: 'slow')
endforeach
