#include <seqan3/io/sequence_file/all.hpp>
#include <seqan3/argument_parser/all.hpp>
#include <seqan3/alphabet/nucleotide/dna5.hpp>

int main(int argc, char const *argv[])
{
	std::string input_file_path{};
	std::string output_file_path{};
	seqan3::argument_parser file_path_parser{"concat_identical_sequence_ids", argc, argv};        // initialise file_path_parser

    file_path_parser.add_option(input_file_path, 'i', "in-file", "Input the complete Path of the Sequence-Inputfile including Filename and Suffix.",
								seqan3::option_spec::REQUIRED, seqan3::input_file_validator{});
	file_path_parser.add_option(output_file_path, 'o', "out-file", "Input the complete Path of the Sequence-Outputfile including Filename and Suffix.",
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

	//Read File
	  seqan3::sequence_file_input input_file{input_file_path};
	  std::unordered_map<seqan3::dna5_vector, std::string> seq_map{};

	  //Iterate over all sequences in the input file and use sequences as keys.
	  //concatenate ID's if there is already an entry for that ID in the map.
	  //should we use multimap instead and do the joining of ids later?
	  for(auto [seq, id, qual] : input_file)
	  {
		auto it = map.find(seq);

		if (it != map.end())
		{
			it->second += "|" + id;
		}
		else
		{
			seq_map.emplace(seq, id);
		}
	  }
	  //iterate over all sequences and write to output_file.
	  seqan3::sequence_file_output output_file {output_file_path};
	  for (auto element : seq_map)
	  {
		  output_file.emplace_back(element.first, element.second);
	  }

	return 0;
}
