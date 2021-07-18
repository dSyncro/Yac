#pragma once

#include <unordered_map>

#include "VariableData.h"

namespace Yac::Runtime {

	struct Stack;

	class StackFrame {

	public:

		StackFrame(Stack& stack);
		StackFrame(StackFrame* parent);

		ByteT* getData() const noexcept;
		ByteT* getDataAt(ptrdiff_t offset) const noexcept { return getData() + offset; }

		ptrdiff_t getLocation() const noexcept { return _location; }
		ptrdiff_t getEndLocation() const noexcept { return _location + _end; }

		StackFrame* getParent() const noexcept { return _parent; }

		bool canPush() const noexcept;
		bool isDeclared(const std::string& name) const noexcept;

		void setVariable(const std::string& name, VariableData data);

		StackFrame* findVariableScope(const std::string& name);

		/**
		 * @brief Find variable in Stack Frame.
		 * @param name Variable name.
		 * @return Variable data.
		*/
		VariableData findVariable(const std::string& name) const;

		/**
		 * @brief Find variable in hierarchy.
		 * @param name Variable name.
		 * @return Variable data.
		*/
		VariableData findInHierarchy(const std::string& name) const;

		/**
		 * @brief Push variable in stack frame. The value will actually be copied to the proper stack location.
		 * @param name Variable name.
		 * @param type Variable type.
		 * @param value Pointer to value.
		*/
		VariableData pushVariable(const std::string& name, VariableData data);

		/**
		 * @brief Push value in stack frame. The value will actually be copied to the proper stack location.
		 * @param type Value type.
		 * @param value Pointer to value.
		*/
		VariableData pushValue(const Yac::Core::TypeSymbol& type, void* value);

	private:

		VariableData* findVariable(const std::string& name);

		Stack* _stack;
		StackFrame* _parent;
		ptrdiff_t _location;
		ptrdiff_t _end;
		std::unordered_map<std::string, VariableData> _variables;
	};

}