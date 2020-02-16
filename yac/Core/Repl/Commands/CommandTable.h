#pragma once

#include "CommandHandler.h"

namespace Yac {
	namespace Core {

		class CommandTable {

		public:

			CommandTable() {}
			CommandTable(std::vector<CommandHandler> handlers);

			void Invoke(const Command& command) const noexcept;

			void InvokeAll(const Command& command) const noexcept;

			inline void Add(const CommandHandler& handler) noexcept { _handlers.push_back(handler); }

			void Register(const CommandHandler& handler) noexcept;

			bool ContainsHandlerFor(const std::string& command) const noexcept;

			inline void Clear() noexcept { _handlers.clear(); }

		private:

			std::vector<CommandHandler> _handlers;
		};

	}
}