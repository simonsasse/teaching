from Bio.Seq import Seq
from Bio.Alphabet import generic_dna
import argparse
from Bio.SeqIO.FastaIO import SimpleFastaParser

file_path_parser= argparse.ArgumentParser(description='translate DNA to Aminoacids.')

file_path_parser.add_argument("input_file", help="Input a complete aminoacid-sequence-filepath including its suffix.")

file_path_parser.add_argument("output_file", help="Input a complete filepath including its suffix for the outputfile.")

args=file_path_parser.parse_args()

#iterate over input_file and output_file and translate all sequences to AA sequences.
with open(args.input_file) as in_handle:
	with open(args.output_file, 'w') as out_handle:
		for title, seq in SimpleFastaParser(in_handle):
			seq=Seq(seq, generic_dna)
			out_handle.write('>'+ title+ '\n')
			out_handle.write(str(seq.translate())+ '\n')
