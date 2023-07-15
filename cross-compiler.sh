[ -f /bin/pacman ] && sudo pacman -Sy base-devel bison flex gmp libmpc mpfr texinfo
[ -f /bin/apt ] && sudo apt-get install build-essential bison flex libgmp3-dev libmpc-dev libmpfr-dev texinfo

# -- Setting up --
export PREFIX="/usr/local/x86_64elfgcc"
export TARGET="x86_64-elf"
export PATH="$PREFIX/bin:$PATH"

# -- Preparing Dir --
# if it fails , it maybe because /tmp was low on space, use another dir
sudo mkdir -p /tmp/src
cd /tmp/src

# -- BINUTILS --
curl -O http://ftp.gnu.org/gnu/binutils/binutils-2.39.tar.gz #44mb
tar xf binutils-2.39.tar.gz
mkdir binutils-build
cd binutils-build
../binutils-2.39/configure --target=$TARGET --enable-interwork --enable-multilib --disable-nls --disable-werror --prefix=$PREFIX 2>&1 | tee configure.log
sudo make all install 2>&1 | tee make.log

# -- GCC --
cd /tmp/src
curl -O https://ftp.gnu.org/gnu/gcc/gcc-12.2.0/gcc-12.2.0.tar.gz #140mb
tar xf gcc-12.2.0.tar.gz
mkdir gcc-build
cd gcc-build
echo Configure: . . . . . . .
../gcc-12.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --disable-libssp --enable-language=c,c++ --without-headers
echo MAKE ALL-GCC:
sudo make all-gcc
echo MAKE ALL-TARGET-LIBGCC:
sudo make all-target-libgcc
echo MAKE INSTALL-GCC:
sudo make install-gcc
echo MAKE INSTALL-TARGET-LIBGCC:
sudo make install-target-libgcc
echo HERE U GO MAYBE:
ls /usr/local/x86_64elfgcc/bin

if [ -f "$HOME/.zshrc" ]; then
	echo "ZSH shell found"
	echo 'export PATH="$PATH:/usr/local/i386elfgcc/bin"' >>~/.zshrc
elif [ -f "$HOME/.bashrc" ]; then
	echo "BASHRC shell found"
	echo 'export PATH="$PATH:/usr/local/i386elfgcc/bin"' >>~/.bashrc
else
	echo "[ ERR ] could not add to path" && exit
fi

echo "Done... Added to path. "
