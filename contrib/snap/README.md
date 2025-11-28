# LORDTROLLCOIN Snap Packaging

Commands for building and uploading a LORDTROLLCOIN Core Snap to the Snap Store. Anyone on amd64 (x86_64), arm64 (aarch64), or i386 (i686) should be able to build it themselves with these instructions. This would pull the official LORDTROLLCOIN binaries from the releases page, verify them, and install them on a user's machine.

## Building Locally
```
sudo apt install snapd
sudo snap install --classic snapcraft
sudo snapcraft
```

### Installing Locally
```
snap install \*.snap --devmode
```

### To Upload to the Snap Store
```
snapcraft login
snapcraft register LORDTROLLCOIN-core
snapcraft upload \*.snap
sudo snap install LORDTROLLCOIN-core
```

### Usage
```
LORDTROLLCOIN-unofficial.cli # for LORDTROLLCOIN-cli
LORDTROLLCOIN-unofficial.d # for LORDTROLLCOINd
LORDTROLLCOIN-unofficial.qt # for LORDTROLLCOIN-qt
LORDTROLLCOIN-unofficial.test # for test_LORDTROLLCOIN
LORDTROLLCOIN-unofficial.tx # for LORDTROLLCOIN-tx
```

### Uninstalling
```
sudo snap remove LORDTROLLCOIN-unofficial
```