###############################################################################
# RPM spec file for SHCF
################################################################################
# Configured to be built by non-root user
################################################################################
#
Summary: Shell Scripting Development Kit(ShSDK) currently supporting bash.
Name: shcf
Version: 0.3.1
Release: 1
License: MIT
URL: http://ismael.casimpan.com/shcf
Group: System
Packager: Ismael Angelo A. Casimpan Jr.
Requires: bash
#~BuildRoot: ~/SHCF_RPMBUILD/

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
mkdir -p $RPM_BUILD_ROOT/opt/icasimpan/shcf

cd $RPM_BUILD_ROOT/opt/icasimpan/shcf
git clone --branch 0.3.1 https://github.com/icasimpan/shcf.git

exit

%files
%attr(0745, nobody, nobody) /opt/icasimpan/shcf/*

%pre

%post
################################################################################
# Post Install stuff here                                                      #
################################################################################
## Move 'projects' directory to /usr/local/src/shcf-projects so it survives uninstall
rm -rf /opt/icasimpan/shcf/projects
mkdir /usr/local/src/shcf-projects
chmod 0757 /usr/local/src/shcf-projects
ln -s /usr/local/src/shcf-projects /opt/icasimpan/shcf/projects

%postun
# remove installed files and links
rm -rf /opt/icasimpan/shcf

%clean
rm -rf $RPM_BUILD_ROOT/shcf

%changelog
* Thu Oct 4 2018 Ismael Angelo A. Casimpan Jr. <ismael.angelo@casimpan.com>
  - Early attempt to build rpm for shcf.
