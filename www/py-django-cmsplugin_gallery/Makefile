# $NetBSD: Makefile,v 1.7 2017/07/30 22:32:26 wiz Exp $

DISTNAME=	cmsplugin_gallery-0.5.5
PKGNAME=	${PYPKGPREFIX}-django-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cmsplugin_gallery/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/centralniak/cmsplugin_gallery
COMMENT=	DjangoCMS image gallery plugin
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-cms-[0-9]*:../../www/py-django-cms
DEPENDS+=	${PYPKGPREFIX}-django-easy-thumbnails-[0-9]*:../../www/py-django-easy-thumbnails
DEPENDS+=	${PYPKGPREFIX}-django-inline-ordering-[0-9]*:../../www/py-django-inline-ordering

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
