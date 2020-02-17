#include <seqan3/io/sequence_file/all.hpp>
#include <seqan3/argument_parser/all.hpp>
#include <seqan3/alphabet/nucleotide/dna5.hpp>

using seqan3::operator""_dna5;

int main(int argc, char const *argv[]) {

	std::string input_file{};

	// initialise file_path_parser
	seqan3::argument_parser file_path_parser{"Count_unkknown_Nucleotides_or_Aminoacids", argc, argv};

    file_path_parser.add_option(input_file, 'i', "in-file", "Input the complete Path of the Sequence-Inputfile including Filename and Suffix.",
								seqan3::option_spec::REQUIRED, seqan3::input_file_validator{});

    try
    {
        file_path_parser.parse();
    }
    catch(seqan3::parser_invalid_argument const & ext)
    {
        seqan3::debug_stream<<"[Parsing error] "<<ext.what() <<'\n';
        return -1;
    }

	//Read File
	seqan3::sequence_file_input file_in{input_file, seqan3::fields<seqan3::field::seq>{}};
	//variable that holds number of unknowns.
	size_t unknown_residues{};
	seqan3::dna5 search_object={'N'_dna5};
	//go through every sequence and sum up unknown residues.
	for(auto [ sequence ] : file_in)
	{
	  unknown_residues+=std::count(sequence.begin(), sequence.end(), search_object);
	}

	std::cout<<"Number of unknown residues in Sequencefile: "<<unknown_residues<<"\n";
	return 0;
}
