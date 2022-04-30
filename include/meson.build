


# TODO: Choose the right values
version_cdata= configuration_data()
version_cdata.set('VERSION_MAJOR', version_major)
version_cdata.set('VERSION_MINOR', version_minor)
version_cdata.set('VERSION_REVISION', '0')
version_cdata.set('VERSION_SUFFIX', '')
version_cdata.set('ABIXML_VERSION_MAJOR', '2')
version_cdata.set('ABIXML_VERSION_MINOR', '1')


configure_file(
  input: 'abg-version.h.in',
  output: 'abg-version.h',
  configuration: version_cdata
)
