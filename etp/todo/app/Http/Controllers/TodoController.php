<?php

namespace App\Http\Controllers;

use App\Models\Todo;
use Illuminate\Http\Request;

class TodoController extends Controller
{
    /**
     * Display a listing of todos.
     */
    public function index()
    {
        $todos = Todo::orderBy('created_at', 'desc')->get();
        return view('todos.index', compact('todos'));
    }

    /**
     * Show the form for creating a new todo.
     */
    public function create()
    {
        return view('todos.create');
    }

    /**
     * Store a newly created todo.
     */
    public function store(Request $request)
    {
        $request->validate([
            'title' => 'required|string|max:255',
            'description' => 'nullable|string',
        ]);

        Todo::create([
            'title' => $request->title,
            'description' => $request->description,
            'completed' => false,
        ]);

        return redirect()->route('todos.index')->with('success', 'Todo created successfully!');
    }

    /**
     * Show the form for editing the specified todo.
     */
    public function edit(Todo $todo)
    {
        return view('todos.edit', compact('todo'));
    }

    /**
     * Update the specified todo.
     */
    public function update(Request $request, Todo $todo)
    {
        $request->validate([
            'title' => 'required|string|max:255',
            'description' => 'nullable|string',
        ]);

        $todo->update([
            'title' => $request->title,
            'description' => $request->description,
        ]);

        return redirect()->route('todos.index')->with('success', 'Todo updated successfully!');
    }

    /**
     * Toggle the completed status of the todo.
     */
    public function toggle(Todo $todo)
    {
        $todo->update([
            'completed' => !$todo->completed,
        ]);

        return redirect()->route('todos.index')->with('success', 'Todo status updated!');
    }

    /**
     * Remove the specified todo.
     */
    public function destroy(Todo $todo)
    {
        $todo->delete();
        return redirect()->route('todos.index')->with('success', 'Todo deleted successfully!');
    }
}
