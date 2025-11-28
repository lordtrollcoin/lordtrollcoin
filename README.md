# Lordtrollcoin (LTR)

![Lordtrollcoin Logo](share/pixmaps/lordtrollcoin256.png)

**The ultimate Troll Face meme cryptocurrency**

Lordtrollcoin is a decentralized, peer-to-peer digital currency inspired by the legendary Troll Face meme. Built on proven blockchain technology, LTR brings the spirit of internet trolling to the world of cryptocurrency.

## 🎭 About Lordtrollcoin

- **Name:** Lordtrollcoin
- **Ticker:** LTR
- **Symbol:** £
- **Block Time:** 60 seconds
- **Algorithm:** Scrypt (Proof of Work)
- **Consensus:** AuxPoW enabled (merge mining)
- **Initial Reward:** 88 LTR per block

## 🌐 Network Information

### Mainnet
- **P2P Port:** 42069
- **RPC Port:** 42070

### Testnet
- **P2P Port:** 42089
- **RPC Port:** 42090

## 🔧 Building from Source

### Prerequisites

#### All Platforms
- C++ compiler with C++11 support
- Boost libraries (1.47.0 or higher)
- OpenSSL
- libevent
- Berkeley DB 5.3 (for wallet functionality)

### Windows (MSYS2/MinGW)

1. **Install MSYS2**
   - Download from https://www.msys2.org/
   - Install to `C:\msys64`

2. **Open MSYS2 MinGW 64-bit terminal and install dependencies:**
   ```bash
   pacman -Syu
   pacman -S mingw-w64-x86_64-toolchain
   pacman -S mingw-w64-x86_64-boost
   pacman -S mingw-w64-x86_64-openssl
   pacman -S mingw-w64-x86_64-libevent
   pacman -S mingw-w64-x86_64-db
   pacman -S mingw-w64-x86_64-qt5
   pacman -S mingw-w64-x86_64-protobuf
   pacman -S mingw-w64-x86_64-qrencode
   pacman -S make autoconf automake libtool pkg-config
   ```

3. **Build Lordtrollcoin:**
   ```bash
   cd /c/Users/YourUsername/Desktop/lordtrollcoin/lordtrollcoin-master/lordtrollcoin-master
   ./autogen.sh
   ./configure --with-gui=qt5
   make -j$(nproc)
   ```

4. **Binaries will be in:**
   - `src/lordtrollcoind.exe` (daemon)
   - `src/lordtrollcoin-cli.exe` (CLI)
   - `src/qt/lordtrollcoin-qt.exe` (GUI wallet)

### Windows (Qt Creator)

1. **Install Qt Creator** from https://www.qt.io/download
2. **Install dependencies** (same as MSYS2 method above)
3. **Open project:**
   - Launch Qt Creator
   - Open `lordtrollcoin-qt.pro`
   - Configure project with MinGW kit
   - Build → Build Project

### macOS (Homebrew)

1. **Install Homebrew** (if not already installed):
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

2. **Install dependencies:**
   ```bash
   brew install automake libtool boost openssl libevent berkeley-db@5 qt5 qrencode protobuf
   ```

3. **Build Lordtrollcoin:**
   ```bash
   cd ~/Desktop/lordtrollcoin/lordtrollcoin-master/lordtrollcoin-master
   ./autogen.sh
   ./configure --with-gui=qt5 LDFLAGS=-L/usr/local/opt/berkeley-db@5/lib CPPFLAGS=-I/usr/local/opt/berkeley-db@5/include
   make -j$(sysctl -n hw.ncpu)
   ```

4. **Binaries will be in:**
   - `src/lordtrollcoind` (daemon)
   - `src/lordtrollcoin-cli` (CLI)
   - `src/qt/lordtrollcoin-qt` (GUI wallet)

### Linux (Ubuntu/Debian)

1. **Install dependencies:**
   ```bash
   sudo apt-get update
   sudo apt-get install build-essential libtool autotools-dev automake pkg-config bsdmainutils python3
   sudo apt-get install libssl-dev libevent-dev libboost-all-dev
   sudo apt-get install libdb5.3-dev libdb5.3++-dev
   
   # For GUI (Qt wallet):
   sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools
   sudo apt-get install libprotobuf-dev protobuf-compiler
   sudo apt-get install libqrencode-dev
   ```

2. **Build Lordtrollcoin:**
   ```bash
   cd ~/Desktop/lordtrollcoin/lordtrollcoin-master/lordtrollcoin-master
   ./autogen.sh
   ./configure --with-gui=qt5
   make -j$(nproc)
   sudo make install  # Optional: install system-wide
   ```

3. **Binaries will be in:**
   - `src/lordtrollcoind` (daemon)
   - `src/lordtrollcoin-cli` (CLI)
   - `src/qt/lordtrollcoin-qt` (GUI wallet)

## 🔥 Firewall & Port Configuration

### Windows Firewall

1. **Open Windows Defender Firewall:**
   - Control Panel → System and Security → Windows Defender Firewall
   - Click "Advanced settings"

2. **Create Inbound Rules:**
   - Click "Inbound Rules" → "New Rule"
   - Select "Port" → Next
   - Select "TCP" and enter port `42069` → Next
   - Select "Allow the connection" → Next
   - Check all profiles → Next
   - Name: "Lordtrollcoin P2P" → Finish
   
   - Repeat for port `42070` (RPC) if needed

### Linux (UFW)

```bash
sudo ufw allow 42069/tcp comment 'Lordtrollcoin P2P'
sudo ufw allow 42070/tcp comment 'Lordtrollcoin RPC'
sudo ufw reload
```

### Linux (iptables)

```bash
sudo iptables -A INPUT -p tcp --dport 42069 -j ACCEPT
sudo iptables -A INPUT -p tcp --dport 42070 -j ACCEPT
sudo iptables-save | sudo tee /etc/iptables/rules.v4
```

### Router Port Forwarding

1. Access your router admin panel (usually http://192.168.1.1 or http://192.168.0.1)
2. Navigate to Port Forwarding section
3. Add new rule:
   - **Service Name:** Lordtrollcoin
   - **External Port:** 42069
   - **Internal Port:** 42069
   - **Internal IP:** Your computer's local IP
   - **Protocol:** TCP
4. Save and apply changes

## 🚀 Usage

### GUI Wallet (lordtrollcoin-qt)

**Windows:**
```bash
lordtrollcoin-qt.exe
```

**macOS/Linux:**
```bash
./lordtrollcoin-qt
```

The GUI wallet provides a user-friendly interface for:
- Sending and receiving LTR
- Viewing transaction history
- Managing addresses
- Encrypting wallet
- Viewing network status

### Daemon (lordtrollcoind)

**Start the daemon:**
```bash
lordtrollcoind -daemon
```

**Check status:**
```bash
lordtrollcoin-cli getinfo
```

**Get blockchain info:**
```bash
lordtrollcoin-cli getblockchaininfo
```

**Get network info:**
```bash
lordtrollcoin-cli getnetworkinfo
```

**Stop the daemon:**
```bash
lordtrollcoin-cli stop
```

### Configuration File

Create `lordtrollcoin.conf` in your data directory:

**Windows:** `%APPDATA%\Lordtrollcoin\lordtrollcoin.conf`  
**macOS:** `~/Library/Application Support/Lordtrollcoin/lordtrollcoin.conf`  
**Linux:** `~/.lordtrollcoin/lordtrollcoin.conf`

**Example configuration:**
```conf
# Network
port=42069
rpcport=42070

# RPC Settings
server=1
rpcuser=lordtrollrpc
rpcpassword=YourSecurePasswordHere
rpcallowip=127.0.0.1

# Connection settings
maxconnections=125

# Logging
debug=0
```

## 🔄 Initial Sync

The first time you run Lordtrollcoin, it will need to download and verify the entire blockchain. This process can take several hours depending on your internet connection and hardware.

**Tips for faster sync:**
- Ensure ports 42069 is open and forwarded
- Use an SSD for the data directory
- Ensure stable internet connection
- Be patient - the sync will complete!

**Monitor sync progress:**
```bash
lordtrollcoin-cli getblockchaininfo
```

Look for the `blocks` and `headers` fields. When they match, sync is complete.

## 💼 Wallet Management

### Create New Wallet

The wallet is created automatically on first run.

### Backup Wallet

**GUI:** File → Backup Wallet  
**CLI:**
```bash
lordtrollcoin-cli backupwallet /path/to/backup/wallet.dat
```

### Encrypt Wallet

**GUI:** Settings → Encrypt Wallet  
**CLI:**
```bash
lordtrollcoin-cli encryptwallet "YourSecurePassphrase"
```

⚠️ **IMPORTANT:** After encrypting, the daemon will shut down. Restart it and unlock when needed.

### Unlock Wallet

```bash
lordtrollcoin-cli walletpassphrase "YourPassphrase" 600
```

(Unlocks for 600 seconds)

## 🎯 Mining

Lordtrollcoin uses Scrypt algorithm and supports merge mining (AuxPoW).

**Solo mining (not recommended):**
```bash
lordtrollcoind -gen=1 -genproclimit=$(nproc)
```

**Pool mining:** Use a compatible Scrypt mining pool and point your miners to the pool address.

## 🌍 Community & Support

- **GitHub:** https://github.com/lordtrollcoin/lordtrollcoin
- **Email:** reemplazaroth@lordtrollcoin.dev

## 📜 License

Lordtrollcoin is released under the terms of the MIT license. See [COPYING](COPYING) for more information.

## 🙏 Acknowledgments

Lordtrollcoin is based on Dogecoin, which is based on Bitcoin Core and Litecoin. We thank all the developers who contributed to these projects.

---

**Troll Face reigns forever! 🎭**
