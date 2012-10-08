#ifndef UCC_GEOMETRY_H
#define UCC_GEOMETRY_H

#include "Generic.h"

namespace UCX {
	namespace Core {

		template<typename T>
		class Vector2D {
		public:
			T X;
			T Y;
		};

		template<typename T>
		class Vector3D {
		public:
			T X;
			T Y;
			T Z;
		};

		typedef Vector3D<int> DWPoint3D;
		typedef Vector3D<short> WPoint3D;
		typedef Vector3D<float> FPoint3D;

	};
};

#endif