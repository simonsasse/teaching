#include <seqan3/io/alignment_file/all.hpp>
#include <filesystem>


int main(int argc, char const *argv[])
{
	std::filesystem::path dir = "/Users/simsalabim/Google Drive/SHK-Stelle/tutorial/source/data/";
    seqan3::alignment_file_output{"/Users/simonsasse97/Google Drive/SHK-Stelle/tutorial/source/data/output.bam"} = seqan3::alignment_file_input{"/Users/simonsasse97/Google Drive/SHK-Stelle/tutorial/source/data/input-test.sam"};
    return 0;
}
