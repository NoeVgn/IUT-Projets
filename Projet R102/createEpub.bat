@echo off
IF NOT EXIST mimetype echo application/epub+zip > mimetype
IF EXIST le_manoir_de_l_enfer.epub del le_manoir_de_l_enfer.epub
C:\"Program Files"\7-Zip\7z.exe a le_manoir_de_l_enfer.epub mimetype
C:\"Program Files"\7-Zip\7z.exe a le_manoir_de_l_enfer.epub OEBPS META-INF
echo ############################
echo EPUB CREATED SUCCESSFULLY
echo ############################