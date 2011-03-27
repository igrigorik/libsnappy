require 'bundler'
Bundler::GemHelper.install_tasks

require 'rspec/core/rake_task'
require 'rake/extensiontask'

Rake::ExtensionTask.new do |ext|
  ext.name = 'libsnappy'
  ext.ext_dir = 'ext'
  ext.lib_dir = 'lib'
  ext.config_script = 'extconf.rb'
end

desc "Run all RSpec tests"
RSpec::Core::RakeTask.new(:spec)

desc "Build libsnappy, then run tests."
task :default => [:compile, :spec]