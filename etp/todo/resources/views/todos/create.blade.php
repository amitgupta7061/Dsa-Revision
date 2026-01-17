@extends('layouts.app')

@section('title', 'Create Todo')

@section('content')
    <div class="card">
        <div style="margin-bottom: 30px;">
            <a href="{{ route('todos.index') }}" class="btn btn-secondary btn-sm" style="margin-bottom: 20px;">
                ← Back to List
            </a>
            <h2 style="font-size: 1.5rem; color: #fff;">✨ Create New Todo</h2>
        </div>

        <form action="{{ route('todos.store') }}" method="POST">
            @csrf

            <div class="form-group">
                <label for="title">Title *</label>
                <input type="text" name="title" id="title" class="form-control" placeholder="What needs to be done?"
                    value="{{ old('title') }}" required>
                @error('title')
                    <span class="error-text">{{ $message }}</span>
                @enderror
            </div>

            <div class="form-group">
                <label for="description">Description (optional)</label>
                <textarea name="description" id="description" class="form-control"
                    placeholder="Add more details about this task...">{{ old('description') }}</textarea>
                @error('description')
                    <span class="error-text">{{ $message }}</span>
                @enderror
            </div>

            <div style="display: flex; gap: 15px; margin-top: 30px;">
                <button type="submit" class="btn btn-success">
                    🚀 Create Todo
                </button>
                <a href="{{ route('todos.index') }}" class="btn btn-secondary">
                    Cancel
                </a>
            </div>
        </form>
    </div>
@endsection