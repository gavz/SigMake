#pragma once

struct SIG_DESCRIPTOR_ENTRY
{
	BYTE Value;
	BYTE Wildcard;
};

#pragma warning(push)
#pragma warning(disable: 4200)// nonstandard extension used : zero-sized array in struct/union
struct SIG_DESCRIPTOR
{
	ULONG Count;
	SIG_DESCRIPTOR_ENTRY Entries[0];
};
#pragma warning(pop)

SIG_DESCRIPTOR *AllocDescriptor(ULONG Count);
void TrimDescriptor(SIG_DESCRIPTOR *Descriptor);
void ShortenDescriptor(SIG_DESCRIPTOR *Descriptor);

void DescriptorToCode(SIG_DESCRIPTOR *Descriptor, char **Data, char **Mask);
void DescriptorToIDA(SIG_DESCRIPTOR *Descriptor, char **Data);
void DescriptorToCRC(SIG_DESCRIPTOR *Descriptor, char *Data, char *Mask, size_t DataSize, size_t MaskSize);

SIG_DESCRIPTOR *DescriptorFromCode(char *Data, char *Mask);
SIG_DESCRIPTOR *DescriptorFromIDA(char *Data);
SIG_DESCRIPTOR *DescriptorFromCRC(char *Data);