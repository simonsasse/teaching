from Bio.SeqIO.FastaIO import SimpleFastaParser
import argparse

file_path_parser= argparse.ArgumentParser(description='Count unknown aminoacids.')
file_path_parser.add_argument("input_file", help="Input a complete aminoacid-sequence-filepath including its suffix.")

args=file_path_parser.parse_args()

count_unknown = 0
# We only count 'N' as unknown.
with open(args.input_file) as in_handle:
    for title, seq in SimpleFastaParser(in_handle):
        count_unknown += seq.count('N')
print("#Unkowns: ",count_unknown)
