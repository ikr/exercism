#ifndef RNA_TRANSCRIPTION_H
#define RNA_TRANSCRIPTION_H
#include <string>

namespace transcription {
char to_rna(const char nucleotide);
std::string to_rna(std::string seq);
} // namespace transcription

#endif // RNA_TRANSCRIPTION_H
