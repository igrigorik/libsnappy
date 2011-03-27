require 'mkmf'

extension_name = 'libsnappy'
$LIBS << " -lstdc++ -lsnappy"

create_makefile(extension_name)