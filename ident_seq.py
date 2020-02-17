#use SimpleFastaParser because its faster than SeqIO
from Bio.SeqIO.FastaIO import SimpleFastaParser
from collections import defaultdict
import argparse
#using sequence as key and id's as items
seq_list = defaultdict(list)

file_path_parser= argparse.ArgumentParser(description='concatenate ids of identical sequences and remove duplicates.')

file_path_parser.add_argument("input_file", help="Input a complete sequence-filepath including its suffix.")

file_path_parser.add_argument("output_file", help="Input a complete filepath including its suffix for the outputfile.")

args=file_path_parser.parse_args()
#Iterate over all sequences in the input file and use sequences as keys
with open(args.input_file) as in_handle:
    for title, seq in SimpleFastaParser(in_handle):
        seq_list[seq].append(title)

#iterate over all sequences and concatenate corresponding ID's and write to output_file.
with open(args.output_file, 'w') as output:
    for seq, ids in seq_list.items():
        output.write(">{}\n".format('|'.join(ids)))
        output.write(seq+"\n")
