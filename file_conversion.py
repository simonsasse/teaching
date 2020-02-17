from Bio import SeqIO
import argparse

file_path_parser= argparse.ArgumentParser(description='Convert Files.')

file_path_parser.add_argument("input_file", help="Input a complete aminoacid-sequence-filepath including its suffix.",
								type=argparse.FileType('r'))
file_path_parser.add_argument("input_file_format", help="Input inputfile format.")

file_path_parser.add_argument("output_file", help="Input a complete filepath including its suffix for the outputfile.",
								type=argparse.FileType('w'))
file_path_parser.add_argument("output_file_format", help="Input outputfile format.")

args=file_path_parser.parse_args()
#use build in file conversion
SeqIO.convert(args.input_file, args.input_file_format, args.output_file, args.output_file_format)
