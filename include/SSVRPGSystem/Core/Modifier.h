// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVRPG_MODIFIER
#define SSVRPG_MODIFIER

#include <SSVUtils/SSVUtils.h>

namespace ssvrpg
{
	template<typename T> class Value;

	template<typename T> class Modifier : public ssvu::MemoryManageable
	{
		private:
			int priority{0};

		public:
			ssvu::Delegate<void, Value<T>&> onAdd;
			ssvu::Delegate<void, Value<T>&> onRemove;
			ssvu::Delegate<void, Value<T>&, T&> onCompute;

			Modifier(int mPriority = 0) : priority{mPriority} { }
			~Modifier() = default;

			// Setters
			void setPriority(int mPriority) { priority = mPriority; }

			// Getters
			int getPriority() const { return priority; }
	};
}

#endif
