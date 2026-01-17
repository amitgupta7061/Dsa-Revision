@extends('layouts.app')

@section('title', 'My Todos')

@section('content')
    <div class="card">
        <div style="display: flex; justify-content: space-between; align-items: center; margin-bottom: 30px;">
            <h2 style="font-size: 1.5rem; color: #fff;">📋 Your Tasks</h2>
            <a href="{{ route('todos.create') }}" class="btn btn-primary">
                <span>➕</span> Add New Todo
            </a>
        </div>

        @if($todos->isEmpty())
            <div style="text-align: center; padding: 60px 20px;">
                <div style="font-size: 4rem; margin-bottom: 20px;">🎉</div>
                <h3 style="font-size: 1.5rem; color: #fff; margin-bottom: 10px;">All caught up!</h3>
                <p style="color: #888;">You have no todos yet. Create one to get started!</p>
            </div>
        @else
            <div class="todo-list">
                @foreach($todos as $todo)
                    <div class="todo-item {{ $todo->completed ? 'completed' : '' }}" style="
                                    display: flex;
                                    align-items: center;
                                    gap: 15px;
                                    padding: 20px;
                                    background: {{ $todo->completed ? 'rgba(16, 185, 129, 0.1)' : 'rgba(255, 255, 255, 0.03)' }};
                                    border-radius: 12px;
                                    margin-bottom: 12px;
                                    border: 1px solid {{ $todo->completed ? 'rgba(16, 185, 129, 0.3)' : 'rgba(255, 255, 255, 0.05)' }};
                                    transition: all 0.3s ease;
                                ">
                        <form action="{{ route('todos.toggle', $todo) }}" method="POST" style="display: flex;">
                            @csrf
                            @method('PATCH')
                            <button type="submit" style="
                                            width: 28px;
                                            height: 28px;
                                            border-radius: 50%;
                                            border: 2px solid {{ $todo->completed ? '#10b981' : '#a855f7' }};
                                            background: {{ $todo->completed ? '#10b981' : 'transparent' }};
                                            cursor: pointer;
                                            display: flex;
                                            align-items: center;
                                            justify-content: center;
                                            transition: all 0.3s ease;
                                        ">
                                @if($todo->completed)
                                    <span style="color: white; font-size: 14px;">✓</span>
                                @endif
                            </button>
                        </form>

                        <div style="flex: 1; min-width: 0;">
                            <h4 style="
                                            font-size: 1.1rem;
                                            color: {{ $todo->completed ? '#888' : '#fff' }};
                                            text-decoration: {{ $todo->completed ? 'line-through' : 'none' }};
                                            margin-bottom: 5px;
                                        ">{{ $todo->title }}</h4>
                            @if($todo->description)
                                <p style="
                                                    color: #666;
                                                    font-size: 0.9rem;
                                                    text-decoration: {{ $todo->completed ? 'line-through' : 'none' }};
                                                ">{{ $todo->description }}</p>
                            @endif
                            <span style="font-size: 0.75rem; color: #555;">{{ $todo->created_at->diffForHumans() }}</span>
                        </div>

                        <div class="action-buttons">
                            <a href="{{ route('todos.edit', $todo) }}" class="btn btn-warning btn-sm">✏️ Edit</a>
                            <form action="{{ route('todos.destroy', $todo) }}" method="POST"
                                onsubmit="return confirm('Are you sure you want to delete this todo?');">
                                @csrf
                                @method('DELETE')
                                <button type="submit" class="btn btn-danger btn-sm">🗑️ Delete</button>
                            </form>
                        </div>
                    </div>
                @endforeach
            </div>

            <div
                style="margin-top: 30px; padding-top: 20px; border-top: 1px solid rgba(255,255,255,0.1); display: flex; justify-content: space-between; color: #888;">
                <span>📊 Total: {{ $todos->count() }} tasks</span>
                <span>✅ Completed: {{ $todos->where('completed', true)->count() }}</span>
            </div>
        @endif
    </div>
@endsection