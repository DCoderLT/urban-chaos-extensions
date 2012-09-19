#ifndef UCE_FILESYSTEM_H
#define UCE_FILESYSTEM_H

namespace UCX {
	namespace Ext {
		namespace FileSystem {
			wchar_t * PathTo(wchar_t *buffer, wchar_t * relPath);

			void CreateFolder(wchar_t * dir);
		};
	};
};

#endif
