#!/bin/bash

echo 'Analiza pliku z adnotacja'
echo '#########################'
wget ftp://ftp.ensembl.org/pub/release-99/gff3/saccharomyces_cerevisiae/Saccharomyces_cerevisiae.R64-1-1.99.gff3.gz
gunzip Saccharomyces_cerevisiae.R64-1-1.99.gff3.gz
gene_number=$(grep -P "\tgene\t" Saccharomyces_cerevisiae.R64-1-1.99.gff3 | wc -l)
echo "Liczba genow: $gene_number"
mrna_number=$(grep -P "sgd\tmRNA\t" Saccharomyces_cerevisiae.R64-1-1.99.gff3 | wc -l)
echo "Liczba mRNA: $mrna_number"
ncrna_number=$(grep -P "\tncRNA_gene\t" Saccharomyces_cerevisiae.R64-1-1.99.gff3 | wc -l)
echo "Liczba genów niekodujących białka: $ncrna_number"
biotype_type=$(grep -P "\tgene\t" Saccharomyces_cerevisiae.R64-1-1.99.gff3 | grep -o "biotype=\w*" | sort | uniq)
echo "Rodzaj biotypów genów: $biotype_type"
biotype_number=$(grep -P "\tgene\t" Saccharomyces_cerevisiae.R64-1-1.99.gff3 | grep -o "biotype=\w*" | sort | uniq | wc -l)
echo "Liczba biotypów genów: $biotype_number"
ribosomal_protein=$(grep -P "\tgene\t" Saccharomyces_cerevisiae.R64-1-1.99.gff3 | grep "ribosomal protein" | cut -f1 | sort | uniq)
echo "Chromosomy, w których kodowane są geny związane z ekspresją białek rybosomalnych: $ribosomal_protein"
chromosomes_lengths=$(grep -P "##sequence-region   " Saccharomyces_cerevisiae.R64-1-1.99.gff3 | cut -d ' ' -f4,6)
echo "Zestawienie długości chromosomów:"
echo "$chromosomes_lengths"
grep -v "^#" Saccharomyces_cerevisiae.R64-1-1.99.gff3 | cut -f1,4,5,9 | cut -d ";" -f1 >Saccharomyces_cerevisiae.R64-1-1.99.BED
show_bed_format=$(head -15 Saccharomyces_cerevisiae.R64-1-1.99.BED)
echo "Format BED:"
echo "$show_bed_format"

