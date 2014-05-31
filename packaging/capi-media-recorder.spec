Name:       capi-media-recorder
Summary:    A Recorder library in Tizen C API
%if 0%{?tizen_profile_mobile}
Version:    0.1.4
%else
Version:    0.1.19
%endif
Release:    1
Group:      libdevel
License:    Apache-2.0
Source0:    %{name}-%{version}.tar.gz
BuildRequires:  cmake
BuildRequires:  pkgconfig(dlog)
BuildRequires:  pkgconfig(mm-camcorder)
BuildRequires:  pkgconfig(audio-session-mgr)
BuildRequires:  pkgconfig(capi-base-common)
BuildRequires:  pkgconfig(capi-media-camera)
BuildRequires:  pkgconfig(capi-media-audio-io)
%if "%{_repository}" == "wearable"
BuildRequires:  pkgconfig(gstreamer-0.10)
%endif
Requires(post): /sbin/ldconfig  
Requires(postun): /sbin/ldconfig

%description

%package devel
Summary:  A Recorder library in Tizen C API (Development)
Group:    TO_BE/FILLED_IN
Requires: %{name} = %{version}-%{release}

%description devel

%prep
%setup -q

%build
%if 0%{?tizen_profile_wearable}
export CFLAGS+=" -DUSE_ASM_LATEST"
cd ./wearable
%else
cd ./mobile
%endif
MAJORVER=`echo %{version} | awk 'BEGIN {FS="."}{print $1}'`
cmake . -DCMAKE_INSTALL_PREFIX=/usr -DFULLVER=%{version} -DMAJORVER=${MAJORVER}


make %{?jobs:-j%jobs}

%install
%if 0%{?tizen_profile_wearable}
cd ./wearable
%else
cd ./mobile
%endif
rm -rf %{buildroot}
mkdir -p %{buildroot}/usr/share/license
cp LICENSE.APLv2 %{buildroot}/usr/share/license/%{name}

%make_install

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig


%files
%if 0%{?tizen_profile_mobile}
%manifest ./mobile/capi-media-recorder.manifest
%endif
%{_libdir}/libcapi-media-recorder.so.*
%{_datadir}/license/%{name}

%files devel
%{_includedir}/media/recorder.h
%{_libdir}/pkgconfig/*.pc
%{_libdir}/libcapi-media-recorder.so


