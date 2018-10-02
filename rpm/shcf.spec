Name: shcf
Version: 1.0.0
Release: 1%{?dist}
Summary: Shell Scripting Development Kit(ShSDK) currently supporting bash.
Group: System
License: MIT
URL: http://ismael.casimpan.com/shcf
Source0: shcf-%{version}.tar.gz
BuildArch: noarch
#~BuildRequires: tarantool-devel >= 1.6.8.0
#~Requires: bash

%description
Shell Scripting Development Kit(ShSDK) currently supporting bash.

%prep
#%setup -q -n luakit-%{version}
%setup -q -n shcf-%{version}

%check
#./test/luakit.test.lua

%install
# Create /usr/share/shcf
mkdir -p %{buildroot}%{_datadir}/shcf
cp -Rfv shcf/* %{buildroot}%{_datadir}/shcf

%files
%dir %{_datadir}/shcf
%{_datadir}/shcf
%doc README.md
%{!?_licensedir:%global license %doc}
%license LICENSE AUTHORS

%changelog
* Mon Oct 2 2018 Ismael Angelo Casimpan Jr <ismael.angelo@casimpan.com> 1.0.0-1
- shcf initial rpm.

