# $NetBSD: Makefile,v 1.107 2017/03/13 09:20:24 wiz Exp $

DISTNAME=	mc-4.8.19
CATEGORIES=	sysutils
MASTER_SITES=	http://www.midnight-commander.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://www.midnight-commander.org/
COMMENT=	User-friendly file manager and visual shell
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		pkg-config unzip:run perl:build gmake
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

# don't want to pull in python
CHECK_INTERPRETER_SKIP+=	libexec/mc/extfs.d/s3+
CHECK_INTERPRETER_SKIP+=	libexec/mc/extfs.d/uc1541

# save copies of the configure arguments, harmless
CHECK_WRKREF_SKIP+=	bin/mc
CHECK_WRKREF_SKIP+=	bin/mcdiff
CHECK_WRKREF_SKIP+=	bin/mcedit
CHECK_WRKREF_SKIP+=	bin/mcview

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
PLIST_SRC+=		${PKGDIR}/PLIST.cons.saver
.endif

# we need working e2fsprogs and gpm packages first
CONFIGURE_ARGS+=	--without-ext2undel
CONFIGURE_ARGS+=	--without-gpm-mouse
CONFIGURE_ARGS+=	UNZIP=${TOOLS_PATH.unzip} ZIP=${TOOLS_PATH.zip}

PLIST_SRC+=		${PKGDIR}/PLIST

.include "options.mk"

EGDIR=			${PREFIX}/share/examples/mc

CONFFILES+=	edit.indent.rc
CONFFILES+=	filehighlight.ini
CONFFILES+=	mc.default.keymap
CONFFILES+=	mc.emacs.keymap
CONFFILES+=	mc.ext
CONFFILES+=	mc.keymap
CONFFILES+=	mc.menu
CONFFILES+=	mcedit.menu
CONFFILES+=	sfs.ini

OWN_DIRS+=	${PKG_SYSCONFDIR}/mc

.for i in ${CONFFILES}
CONF_FILES+=	${EGDIR}/${i} ${PKG_SYSCONFDIR}/mc/${i}
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.26.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
