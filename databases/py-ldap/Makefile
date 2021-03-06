# $NetBSD: Makefile,v 1.79 2017/10/24 04:45:56 adam Exp $

DISTNAME=	python-ldap-2.4.45
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-ldap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.python-ldap.org/
COMMENT=	LDAP client API for Python
LICENSE=	python-software-foundation

USE_TOOLS+=		pax

PY_LDAP_LIBRARY_DIRS=		${BUILDLINK_PREFIX.openldap-client}/lib
PY_LDAP_INCLUDE_DIRS=		${BUILDLINK_PREFIX.openldap-client}/include
PY_LDAP_LIBS=			ldap_r lber ssl crypto
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 2.4.43

.include "options.mk"

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	pre-configure
SUBST_FILES.setup=	setup.cfg
SUBST_VARS.setup=	PY_LDAP_LIBRARY_DIRS PY_LDAP_INCLUDE_DIRS PY_LDAP_LIBS

REPLACE_PYTHON=		Lib/ldap/controls/readentry.py

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
