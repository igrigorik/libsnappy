require 'rspec'
require 'snappy'

describe Snappy do
  it 'should compress data' do
    lambda do
      Snappy.compress('abcdefg')
    end.should_not raise_error
  end

  it 'should uncompress data' do
    lambda do
      Snappy.uncompress(Snappy.compress('abcdefg'))
    end.should_not raise_error
  end

  it 'should roundtrip the data' do
    original = 'abcdefg' * 100

    compressed = Snappy.compress(original)
    uncompressed = Snappy.uncompress(compressed)

    original.should == uncompressed
    compressed.size.should < original.size
  end
end