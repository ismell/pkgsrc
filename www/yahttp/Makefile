# $NetBSD: Makefile,v 1.10 2017/09/16 19:27:26 wiz Exp $

DISTNAME=	yahttp-0.1.5
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=cmouse/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cmouse/yahttp/
COMMENT=	Yet Another HTTP Library
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	aclocal autoconf autoheader automake

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
