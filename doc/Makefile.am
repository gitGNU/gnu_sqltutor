## Process this file with automake to produce Makefile.in -*-Makefile-*-
## Copyright (C) 2008, 2014 Ales Cepek

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

AM_MAKEINFOFLAGS  = --no-split
info_TEXINFOS     = sqltutor.texi
sqltutor_TEXINFOS = intro.texi concepts.texi install.texi internals.texi \
                    gpl-3.0.texi fdl.texi

EXTRA_DIST = \
   fig/sqltutor-dialog-1.eps \
   fig/sqltutor-dialog-1.pdf \
   fig/sqltutor-dialog-1.png \
   fig/sqltutor-dialog-2.eps \
   fig/sqltutor-dialog-2.pdf \
   fig/sqltutor-dialog-2.png \
   fig/sqltutor-dialog-3.eps \
   fig/sqltutor-dialog-3.pdf \
   fig/sqltutor-dialog-3.png \
   fig/sqltutor-install.eps  \
   fig/sqltutor-install.pdf  \
   fig/sqltutor-install.png  \
   fig/schema.eps \
   fig/schema.pdf \
   fig/schema.png \
   fig/schema.txt


CLEANFILES =
CLEANDIRS  =

# Doxygen section dopted from bison-2.4/doc/Makefile.am

## -------------- ##
## Doxygenation.  ##
## -------------- ##

DOXYGEN = doxygen

doxygen: Doxyfile
	$(DOXYGEN)

edit = sed -e 's,@PACKAGE_NAME\@,$(PACKAGE_NAME),g' \
           -e 's,@PACKAGE_VERSION\@,$(PACKAGE_VERSION),g' \
           -e 's,@top_builddir\@,$(top_builddir),g' \
           -e 's,@top_srcdir\@,$(top_srcdir),g'

EXTRA_DIST += Doxyfile.in
CLEANFILES += Doxyfile
# Sed is used to generate Doxyfile from Doxyfile.in instead of
# configure, because the former is way faster than the latter.
Doxyfile: $(srcdir)/Doxyfile.in
	$(edit) $(srcdir)/Doxyfile.in >Doxyfile

CLEANDIRS += manual latex

download-gendocs.sh:
	rm -f gendocs.sh* gendocs_template*
	wget http://savannah.gnu.org/cgi-bin/viewcvs/~checkout~/texinfo/texinfo/util/gendocs.sh
	wget http://savannah.gnu.org/cgi-bin/viewcvs/~checkout~/texinfo/texinfo/util/gendocs_template
	chmod +x gendocs.sh

run-gendocs.sh:
	make info
	rm -rf manual
	./gendocs.sh --texi2html --email cepek@gnu.org sqltutor "GNU Sqltutor manual"

#	ls -l  manual/html_*/index.html
#	rm -fv manual/html_*/index.html
#	cp -v  .symlinks manual/html_chapter
#	cp -v  .symlinks manual/html_node
#	cp -v  .symlinks manual/html_section
#	echo "../fig fig" > manual/.symlinks
