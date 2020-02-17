#include <seqan3/alphabet/all.hpp>
#include <seqan3/range/views/all.hpp>
#include <seqan3/argument_parser/all.hpp>
#include <seqan3/io/sequence_file/all.hpp>
#include <typeinfo>

int main(int argc, char const *argv[])
{
	std::string input_file_path{};
	std::string output_file_path{};
	// initialise file_path_parser
	seqan3::argument_parser file_path_parser{"translate_Nucleotides_to_protein", argc, argv};

    file_path_parser.add_option(input_file_path, 'i', "in-file", "Input the complete Path of the Nucleotide-Sequence-Inputfile including Filename and Suffix.",
								seqan3::option_spec::REQUIRED, seqan3::input_file_validator{});
	file_path_parser.add_option(output_file_path, 'o', "out-file", "Input the complete Path of the Protein-Sequence-Outputfile including Filename and Suffix.",
								seqan3::option_spec::REQUIRED, seqan3::output_file_validator{});

	try
	{
		file_path_parser.parse();
	}
	catch(seqan3::parser_invalid_argument const & ext)
	{
		seqan3::debug_stream<<"[Parsing error] "<<ext.what() <<'\n';
		return -1;
	}

	seqan3::sequence_file_input input_file{input_file_path};
	seqan3::sequence_file_output output_file {output_file_path};

	for(auto [seq, id, qual] : input_file)
	{
		int v = seq | seqan3::views::translate_single(seqan3::translation_frames::FWD_FRAME_0);
		output_file.emplace_back(v, id);
	}
	return 0;
}
