// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVRPG_VALUE
#define SSVRPG_VALUE

#include <vector>
#include <functional>
#include <SSVUtils/SSVUtils.h>
#include "SSVRPGSystem/Core/Modifier.h"

namespace ssvrpg
{
	template<typename T> class Value
	{
		private:
			T base, computed;
			std::vector<Value<T>*> dependencies; // not owned
			std::vector<Modifier<T>*> modifiers; // not owned

			void recompute()
			{
				computed = base;
				for(const auto& m : modifiers) m->onCompute(*this, computed);
				onPostCompute();
			}

		public:
			ssvu::Delegate<void()> onPostCompute;

			Value(T mBase) : base{mBase}, computed{base} { }
			~Value() { }

			void addDependency(Value<T>& mValue)
			{
				dependencies.push_back(&mValue);
				mValue.onPostCompute += [&]{ recompute(); };
			}
			void addModifier(Modifier<T>& mModifier)
			{
				modifiers.push_back(&mModifier);
				ssvu::sort(modifiers, [](Modifier<T>* mA, Modifier<T>* mB){ return mA->getPriority() < mB->getPriority(); });
				mModifier.onAdd(*this);

				recompute();
			}
			void removeModifier(Modifier<T>& mModifier)
			{
				ssvu::eraseRemove(modifiers, &mModifier);
				mModifier.onRemove(*this);

				recompute();
			}

			void setBase(T mBase)						{ base = mBase; recompute(); }

			T getBase() const							{ return base; }
			T getComputed() const						{ return computed; }
			std::vector<Modifier<T>*>& getModifiers()	{ return modifiers; }
	};
}

#endif
