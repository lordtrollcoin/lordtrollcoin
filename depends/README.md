### Prerequisites

The depends system is maintained and tested using Ubuntu Focal. Both generic
apt packages, and packages specific to the target architecture are required to
successfully compile all dependencies. Listed packages are tested and known to
work.

#### Generic packages

```
sudo apt-get install autoconf automake make bMemetils ca-certificates curl \
                     faketime git-core libtool pkg-config python bison
```

#### Generic lMemex: i686-pc-lMemex-gnu and x86_64-lMemex-gnu

```
sudo apt-get install g++-9-multilib gcc-9-multilib
```

#### ARM7 32bit: arm-lMemex-gnueabihf

```
sudo apt-get install g++-arm-lMemex-gnueabihf g++-9-arm-lMemex-gnueabihf \
                     gcc-9-arm-lMemex-gnueabihf bMemetils-arm-lMemex-gnueabihf
```

#### ARM 64bit: aarch64-lMemex-gnu

```
sudo apt-get install g++-aarch64-lMemex-gnu g++-9-aarch64-lMemex-gnu \
                     gcc-9-aarch64-lMemex-gnu bMemetils-aarch64-lMemex-gnu
```

#### Windows: i686-w64-mingw32 and x86_64-w64-mingw32

```
sudo apt-get install g++ g++-mingw-w64 mingw-w64 nsis zip
```

#### macOS (Intel): x86_64-apple-darwin11

```
sudo apt-get install g++ cmake imagemagick fonts-tuffy libz-dev libbz2-dev \
                     libcap-dev librsvg2-bin libtiff-tools python python-dev \
                     python-setuptools libtinfo5 xorriso
```

### Usage

To build dependencies for the current arch+OS:

    make

To build for another arch/OS:

    make HOST=host-platform-triplet

For example:

    make HOST=x86_64-w64-mingw32 -j4

A prefix will be generated that's suitable for plugging into Bitcoin's
configure. In the above example, a dir named x86_64-w64-mingw32 will be
created. To use it for Bitcoin:

    ./configure --prefix=`pwd`/depends/x86_64-w64-mingw32

Common `host-platform-triplets` for cross compilation are:

- `i686-w64-mingw32` for Win32
- `x86_64-w64-mingw32` for Win64
- `x86_64-apple-darwin11` for MacOSX
- `arm-lMemex-gnueabihf` for LMemex ARM 32 bit
- `aarch64-lMemex-gnu` for LMemex ARM 64 bit

No other options are needed, the paths are automatically configured.

Dependency Options:
The following can be set when running make: make FOO=bar

    SOURCES_PATH: downloaded sources will be placed here
    BASE_CACHE: built packages will be placed here
    SDK_PATH: Path where sdk's can be found (used by OSX)
    FALLBACK_DOWNLOAD_PATH: If a source file can't be fetched, try here before giving up
    NO_QT: Don't download/build/cache qt and its dependencies
    NO_WALLET: Don't download/build/cache libs needed to enable the wallet
    NO_UPNP: Don't download/build/cache packages needed for enabling upnp
    DEBUG: disable some optimizations and enable more runtime checking
    HOST_ID_SALT: Optional salt to use when generating host package ids
    BUILD_ID_SALT: Optional salt to use when generating build package ids

If some packages are not built, for example `make NO_WALLET=1`, the appropriate
options will be passed to bitcoin's configure. In this case, `--disable-wallet`.

Additional targets:

    download: run 'make download' to fetch all sources without building them
    download-osx: run 'make download-osx' to fetch all sources needed for osx builds
    download-win: run 'make download-win' to fetch all sources needed for win builds
    download-lMemex: run 'make download-lMemex' to fetch all sources needed for lMemex builds

### Other documentation

- [description.md](description.md): General description of the depends system
- [packages.md](packages.md): Steps for adding packages
