#ifndef UCC_SYRINGE_H
#define UCC_SYRINGE_H

#include "Generic.h"

#include "Hashmap.h"

#include <windows.h>

namespace UCX {
	namespace Core {

		class LimitedRegister {
		protected:
			DWORD data;

			WORD * wordData() {
				return reinterpret_cast<WORD *>(&(this->data));
			}

			BYTE * byteData() {
				return reinterpret_cast<BYTE *>(&(this->data));
			}

		public:
			WORD Get16() {
				return *(this->wordData());
			}

			template<typename T>
				inline T Get() {
					return *(reinterpret_cast<T*>(&(this->data)));
				}

			template<typename T>
				inline void Set(T value) {
					this->data = DWORD(value);
				}

			void Set16(WORD value) {
				*(this->wordData()) = value;
			}

		};

		class ExtendedRegister : public LimitedRegister {
		public:
			BYTE Get8Hi() {
				return (this->byteData())[1];
			}

			BYTE Get8Lo() {
				return (this->byteData())[0];
			}

			void Set8Hi(BYTE value) {
				(this->byteData())[1] = value;
			}

			void Set8Lo(BYTE value) {
				(this->byteData())[0] = value;
			}
		};

		class StackRegister : public ExtendedRegister {
		public:
			template<typename T>
				inline T * lea(signed int byteOffset) {
				return reinterpret_cast<T *>(this->data + byteOffset);
			}

			inline DWORD lea(signed int byteOffset) {
				return (DWORD) (((signed int)this->data) + byteOffset);
			}

			template<typename T>
				inline T At(signed int byteOffset) {
				return *(reinterpret_cast<T *>(this->data + byteOffset));
			}

			template<typename T>
				inline void At(signed int byteOffset, T value) {
				*(reinterpret_cast<T *>(this->data + byteOffset)) = value;
			}
		};

		//Macros to make the following a lot easier
		#define REG_FUNCS1(n32, n16, n8hi, n8lo, idx) \
		public: \
			DWORD get_ ## n32 ()\
				{ return regs[idx]; }\
			WORD get_## n16 ()\
				{ return (WORD)(regs[idx] & 0xFFFF); }\
			BYTE get_## n8hi ()\
				{ return (BYTE)((regs[idx] & 0xFFFF) >> 8); }\
			BYTE get_## n8lo ()\
				{ return (BYTE)(regs[idx] & 0xFF); }\
		private: \
			void _set_## n32 (DWORD value)\
				{ regs[idx] = value; }\
			void _set_## n16 (WORD value)\
				{ ((WORD*)&regs[idx])[0] = value; }\
			void _set_## n8hi (BYTE value)\
				{ ((BYTE*)&regs[idx])[1] = value; }\
			void _set_## n8lo (BYTE value)\
				{ ((BYTE*)&regs[idx])[0] = value; }\
		public: \
			template <typename T> inline void Set_## n32(T value)\
				{ regs[idx] = reinterpret_cast<DWORD>(value); } \
			template <typename T> inline void Set_## n16(T value)\
				{ ((WORD*)&regs[idx])[0] = reinterpret_cast<WORD>(value); } \
			template <typename T> inline void Set_## n8hi(T value)\
				{ ((BYTE*)&regs[idx])[1] = reinterpret_cast<BYTE>(value); } \
			template <typename T> inline void Set_## n8lo(T value)\
				{ ((BYTE*)&regs[idx])[0] = reinterpret_cast<BYTE>(value); } \

		#define REG_FUNCS2(n32, n16, idx) \
		public: \
			DWORD Get_ ## n32 () \
				{ return regs[idx]; } \
			WORD Get_## n16 () \
				{ return (WORD)(regs[idx] & 0xFFFF); } \
		private: \
			void set_## n32 (DWORD value) \
				{ regs[idx] = value; } \
			void set_## n16 (WORD value) \
				{ ((WORD*)&regs[idx])[0] = value; } \
		public: \
			template <typename T> inline void Set_## n32(T value)\
				{ regs[idx] = reinterpret_cast<DWORD>(value); } \
			template <typename T> inline void Set_## n16(T value)\
				{ ((WORD*)&regs[idx])[0] = reinterpret_cast<WORD>(value); } \

		#define REG_SHORTCUTS(reg) \
			inline DWORD reg() \
				{ return this->_ ## reg.Get<DWORD>(); } \
			template<typename T> inline T reg() \
				{ return this->_ ## reg.Get<T>(); } \
			template<typename T> inline void reg(T value) \
				{ this->_ ## reg.Set<T>(value); } \

		#define REG_SHORTCUTS_X(r) \
			DWORD r ## X() \
				{ return this->_E ## r ## X.Get16(); } \
			void r ## X(WORD value) \
				{ this->_E ## r ## X.Set16(value); } \

		#define REG_SHORTCUTS_HL(r) \
			DWORD r ## H() \
				{ return this->_E ## r ## X.Get8Hi(); } \
			void r ## H(BYTE value) \
				{ this->_E ## r ## X.Set8Hi(value); } \
			DWORD r ## L() \
				{ return this->_E ## r ## X.Get8Lo(); } \
			void r ## L(BYTE value) \
				{ this->_E ## r ## X.Set8Lo(value); } \

		#define REG_SHORTCUTS_XHL(r) \
			REG_SHORTCUTS_X(r); \
			REG_SHORTCUTS_HL(r); \

		//A pointer to this class is passed as an argument to EXPORT functions
		class REGISTERS
		{
		private:
			DWORD	origin;
			DWORD	flags;
		//	DWORD	regs[8];

			LimitedRegister _EDI;
			LimitedRegister _ESI;
			StackRegister _EBP;
			StackRegister _ESP;
			ExtendedRegister _EBX;
			ExtendedRegister _EDX;
			ExtendedRegister _ECX;
			ExtendedRegister _EAX;

		public:
			DWORD get_Origin()
				{ return this->origin; }

			DWORD EFLAGS()
				{ return this->flags; }
			void EFLAGS(DWORD value)
				{ this->flags = value; }

			REG_SHORTCUTS(EAX);
			REG_SHORTCUTS(EBX);
			REG_SHORTCUTS(ECX);
			REG_SHORTCUTS(EDX);
			REG_SHORTCUTS(ESI);
			REG_SHORTCUTS(EDI);
			REG_SHORTCUTS(ESP);
			REG_SHORTCUTS(EBP);

			REG_SHORTCUTS_XHL(A);
			REG_SHORTCUTS_XHL(B);
			REG_SHORTCUTS_XHL(C);
			REG_SHORTCUTS_XHL(D);

			template<typename T>
				inline T lea_Stack(signed int offset)
					{ return reinterpret_cast<T>(this->_ESP.lea(offset)); }

			template<>
				inline DWORD lea_Stack(signed int offset)
					{ return this->_ESP.lea(offset); }

			template<>
				inline int lea_Stack(signed int offset)
					{ return this->_ESP.lea(offset); }

			template<typename T>
				inline T Stack(signed int offset)
					{ return this->_ESP.At<T>(offset); }

			DWORD Stack32(signed int offset)
					{ return this->_ESP.At<DWORD>(offset); }
			WORD Stack16(signed int offset)
					{ return this->_ESP.At<WORD>(offset); }
			BYTE Stack8(signed int offset)
					{ return this->_ESP.At<BYTE>(offset); }

			template<typename T>
				inline T Base(signed int offset)
					{ return this->_EBP.At<T>(offset); }

			template<typename T>
				inline void Stack(signed int offset, T value)
					{ this->_ESP.At<T>(offset, value); }

			void Stack16(signed int offset, WORD value)
					{ this->_ESP.At<WORD>(offset, value); }
			void Stack8(signed int offset, BYTE value)
					{ this->_ESP.At<BYTE>(offset, value); }

			template<typename T>
				inline void Base(signed int offset, T value)
					{ this->_EBP.At<T>(offset, value); }
		};
	};
};

#define GET(clsname, var, reg) \
	clsname var = R->reg<clsname>();

// it's really not a good idea to GET_STACK(not_a_pointer)
// no, really
#define LEA_STACK(clsname, var, offset) \
	clsname var = R->lea_Stack<clsname>(offset);

#define GET_STACK(clsname, var, offset) \
	clsname var = R->Stack<clsname>(offset);

#define GET_BASE(clsname, var, offset) \
	clsname var = R->Base<clsname>(offset);

#define STACK_OFFS(cur_offset, wanted_offset) \
		(cur_offset - wanted_offset)

#include "hookdecl.h"

#endif
