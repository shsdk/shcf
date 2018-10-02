###############################################################################
# Spec file for SHCF - Shell Scripting Development Kit (ShSDK)
################################################################################
#
Summary: Shell Scripting Development Kit(ShSDK) currently supporting bash.
Name: shcf
Version: 1.0.0
Release: 1%{?dist}
License: MIT
URL: http://ismael.casimpan.com/shcf
Group: System
Packager: Ismael Casimpan
Requires: bash
Requires: git
BuildRoot: ~/rpmbuild/

# Build with the following syntax:
# rpmbuild --target noarch -bb shcf.spec

%description
Shell Scripting Development Kit(ShSDK) currently supporting bash.

%prep
################################################################################
# Create the build tree and copy the files from the development directories    #
# into the build tree.                                                         #
################################################################################
echo "BUILDROOT = $RPM_BUILD_ROOT"
mkdir -p $RPM_BUILD_ROOT/usr/local/bin/

cd $RPM_BUILD_ROOT/usr/local/bin/
git clone --branch master https://github.com/icasimpan/shcf.git

exit

%files
%attr(0744, root, root) /usr/local/bin/*

%pre

%post

%postun

%clean
rm -rf $RPM_BUILD_ROOT/usr/local/bin

%changelog
* Mon Oct 1, 2018: Ismael Angelo A. Casimpan Jr. <ismael.angelo@casimpan.com>
  - First creation of rpm package.
