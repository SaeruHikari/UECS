#pragma once

#include "CmptTag.h"

#include "CmptType.h"

#include <set>

namespace Ubpa::UECS {
	// locate components in function's argument list for Archetype
	// TODO: combine with a system function's locator
	class EntityLocator {
	public:
		template<typename TaggedCmptList>
		EntityLocator(TaggedCmptList);

		template<typename... LastFrameCmpts, typename... WriteCmpts, typename... LatestCmpts>
		EntityLocator(TypeList<LastFrameCmpts...>, TypeList<WriteCmpts...>, TypeList<LatestCmpts...>);

		EntityLocator(const CmptType* types, size_t num);

		size_t HashCode() const noexcept { return hashCode; }

		const std::set<CmptType>& LastFrameCmptTypes() const noexcept { return lastFrameCmptTypes; }
		const std::set<CmptType>& WriteCmptTypes() const noexcept { return writeCmptTypes; }
		const std::set<CmptType>& LatestCmptTypes() const noexcept { return latestCmptTypes; }
		const std::set<CmptType>& CmptTypes() const noexcept { return cmptTypes; }

		AccessMode GetCmptTagMode(CmptType type) const;

		bool operator==(const EntityLocator& locator) const noexcept;
	private:
		size_t GenHashCode() const noexcept;

		std::set<CmptType> lastFrameCmptTypes;
		std::set<CmptType> writeCmptTypes;
		std::set<CmptType> latestCmptTypes;
		std::set<CmptType> cmptTypes;

		size_t hashCode;
	};
}

#include "detail/EntityLocator.inl"
