#include <seqan3/io/alignment_file/all.hpp>
#include <seqan3/argument_parser/all.hpp>
#include <seqan3/core/debug_stream.hpp>
#include <string>

int main(int argc, char const *argv[])
{
	//initialize file_path_parser
	seqan3::argument_parser file_path_parser{"Alignmentfile_Conversion", argc, argv};

	std::string input_file{};
	std::string output_file{};

	file_path_parser.add_option(input_file, 'i', "in-file", "Input the complete Path of the Alignment-Inputfile including Filename and Suffix.",
								seqan3::option_spec::REQUIRED, seqan3::input_file_validator{});
    file_path_parser.add_option(output_file, 'o', "out-file", "Input the wished Path of the Alignment-Outputfile including Filename and Suffix.",
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
	//write sequence to new output_file.
	seqan3::alignment_file_output{output_file} = seqan3::alignment_file_input{input_file};
	return 0;
}
