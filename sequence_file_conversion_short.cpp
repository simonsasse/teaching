#include <seqan3/io/sequence_file/all.hpp>
#include <filesystem>

int main(int argc, char const *argv[])
{
	std::filesystem::path dir = "/Users/simsalabim/Google Drive/SHK-Stelle/tutorial/source/data/";
	seqan3::sequence_file_output{dir/"output.fasta"} = seqan3::sequence_file_input{dir/"seq.fastq"};
	return 0;
}
