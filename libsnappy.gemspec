# -*- encoding: utf-8 -*-
$:.push File.expand_path("../lib", __FILE__)

Gem::Specification.new do |s|
  s.name        = "libsnappy"
  s.version     = "0.1.0"
  s.platform    = Gem::Platform::RUBY
  s.authors     = ["Ilya Grigorik", "Michael Bernstein"]
  s.email       = ["ilya@igvita.com", "michael@spaceshipknows.com"]
  s.homepage    = "http://code.google.com/p/snappy/"
  s.summary     = "Snappy, a fast compressor/decompressor (courtesy of Google)"
  s.description = s.summary

  s.rubyforge_project = "libsnappy"
  s.extensions = ["ext/extconf.rb"]

  s.add_development_dependency "rake-compiler", "0.7.6"
  s.add_development_dependency "rspec"

  s.files         = `git ls-files`.split("\n")
  s.test_files    = `git ls-files -- {test,spec,features}/*`.split("\n")
  s.executables   = `git ls-files -- bin/*`.split("\n").map{ |f| File.basename(f) }
  s.require_paths = ["lib"]
end
