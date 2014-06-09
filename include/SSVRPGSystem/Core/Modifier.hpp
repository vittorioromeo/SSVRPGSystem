// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVRPG_MODIFIER
#define SSVRPG_MODIFIER

#include <SSVUtils/SSVUtils.hpp>

namespace ssvrpg
{
	template<typename T> class Value;

	template<typename T> class Modifier
	{
		private:
			int priority{0};

		public:
			ssvu::Delegate<void(Value<T>&)> onAdd;
			ssvu::Delegate<void(Value<T>&)> onRemove;
			ssvu::Delegate<void(Value<T>&, T&)> onCompute;

			Modifier(int mPriority = 0) : priority{mPriority} { }
			~Modifier() = default;

			// Setters
			void setPriority(int mPriority) { priority = mPriority; }

			// Getters
			int getPriority() const { return priority; }
	};
}

#endif
