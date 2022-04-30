
# Single-file tools
tools = [
  'abicompat',
  'abidiff',
  'abidw',
  'abilint',
  'abipkgdiff',
  'abisym',
  'kmidiff',
]
foreach tool : tools
  executable(
    tool,
    tool + '.cc',
    dependencies: [
      libabigail_dep
    ],
    include_directories: [ toplevel_incdir ]
  )
endforeach


executable(
  'abinilint',
  'binilint.cc',
  dependencies: [
    libabigail_dep
  ],
  include_directories: [ toplevel_incdir ]
)

