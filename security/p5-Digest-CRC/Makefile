# $NetBSD: Makefile,v 1.28 2017/09/27 20:43:52 wiz Exp $

DISTNAME=	Digest-CRC-0.22.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/O/OL/OLIMAUL/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-CRC/
COMMENT=	Perl5 extension interface for cyclic redundancy check algorithms
LICENSE=	public-domain

PERL5_PACKLIST=		auto/Digest/CRC/.packlist
WRKSRC=		${WRKDIR}/Digest-CRC-0.22

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
