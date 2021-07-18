#pragma once

#include "StackFrame.h"

namespace Yac::Runtime {

	class VirtualMemory;

	struct Stack {

	public:

		Stack() = delete;
		~Stack();

		/**
		 * @brief Get pointer to stack data.
		 * @return Pointer to stack data.
		*/
		ByteT* getData() const noexcept { return _buffer; }

		/**
		 * @brief Get pointer to stack data at a certain offset from beginning.
		 * @param offset The offset.
		 * @return Pointer to stack data.
		*/
		ByteT* getDataAt(ptrdiff_t offset) const noexcept { return _buffer + offset; }

		VirtualMemory& virtualMemory() { return *_virtualMemory; }
		const VirtualMemory& virtualMemory() const { return *_virtualMemory; }

		/**
		 * @brief Push new Stack Frame.
		 * @return A reference to the new Stack Frame.
		*/
		const StackFrame& pushFrame();

		/**
		 * @brief Pop last Stack Frame.
		 * If we are trying to pop the only frame in the stack, the function will generate a new one.
		 * @return A reference to the Stack Frame that is now in front.
		*/
		const StackFrame& popFrame();

		UIntT getFreeMemory() const noexcept { return _size - _occupied; }
		UIntT getOccupiedMemory() const noexcept { return _occupied; }

		bool canAllocate(UIntT size) const noexcept { return getFreeMemory() >= size; }

		void setVariable(const std::string& name, VariableData data) noexcept { _currentFrame->setVariable(name, data); }
		void reserve(UIntT size) noexcept;

		ByteT* retrieve(VariableData data) { return getDataAt(data.getOffset()); }

		StackFrame& currentFrame() noexcept { return *_currentFrame; }

		VariableData findVariable(const std::string& name) const noexcept { return _currentFrame->findInHierarchy(name); }

		VariableData pushVariable(const std::string& name, VariableData data);
		VariableData pushValue(const Yac::Core::TypeSymbol& type, void* value);

	private:

		Stack(VirtualMemory& virtualMemory);

		UIntT _size;
		UIntT _occupied;
		ByteT* _buffer;
		StackFrame* _currentFrame;
		VirtualMemory* _virtualMemory;

		friend class VirtualMemory;
	};

}