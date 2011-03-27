# Snappy

A Ruby wrapper for Google's fast compressor/decompressor. From Google's own description:

Snappy is a compression/decompression library. It does not aim for maximum compression, or compatibility with any other compression library; instead, it aims for very high speeds and reasonable compression. For instance, compared to the fastest mode of zlib, Snappy is an order of magnitude faster for most inputs, but the resulting compressed files are anywhere from 20% to 100% bigger. On a single core of a Core i7 processor in 64-bit mode, Snappy compresses at about 250 MB/sec or more and decompresses at about 500 MB/sec or more.

Snappy is widely used inside Google, in everything from BigTable and MapReduce to our internal RPC systems. (Snappy has previously been referred to as “Zippy” in some presentations and the likes.)

## Installation

Snappy relies on Rice (Ruby interface for C++ extensions) and assumes that you have Snappy libs installed on your system.

- Grab the latest Snappy build and install it on your system:
    - [http://code.google.com/p/snappy/](http://code.google.com/p/snappy/)
- You may need 'Google Test' and 'Google Flags' to build Snappy:
    - [http://code.google.com/p/googletest/](http://code.google.com/p/googletest/])
    - [http://code.google.com/p/google-gflags/](http://code.google.com/p/google-gflags/)
- Build Rice on your system:
    - follow instructions on [https://github.com/jameskilton/rice](https://github.com/jameskilton/rice)

Once you have Snappy and Rice installed on your system, you can install the gem:

    gem install snappy

## Example

    compressed = Snappy.compress('string to compress')
    uncompressed = Snappy.uncompress(compressed)

For benchmarks and motivation behind Snappy see:

- [http://blog.sesse.net/blog/tech/2011-03-22-19-24_snappy](http://blog.sesse.net/blog/tech/2011-03-22-19-24_snappy)
- [http://pastebin.com/SFaNzRuf](http://pastebin.com/SFaNzRuf)

### License

(MIT License) - Copyright (c) 2011 Ilya Grigorik