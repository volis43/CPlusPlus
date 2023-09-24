#include <Windows.h>

int main()
{
	SHEmptyRecycleBin(NULL, NULL, SHERB_NOCONFIRMATION | SHERB_NOPROGRESSUI | SHERB_NOSOUND);
	return 0;
}
