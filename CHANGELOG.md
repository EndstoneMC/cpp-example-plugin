# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

## [Unreleased]

## [0.5.0] - 2026-03-23

### Changed
- Overhauled plugin examples to focus on essential patterns: lifecycle, commands, events
- Two commands (`/hello`, `/broadcast`) demonstrating dynamic_cast sender checks and server broadcast
- Simplified listener to player join/quit with event priority example
- Simplified source file names (plugin.h, listener.h, plugin.cpp)
- Updated CI to Clang 18, checkout@v6
- README rewritten as a practical template quickstart with renaming guide and release docs

### Added
- AGENTS.md to guide AI coding agents building Endstone C++ plugins
- Release workflow with changelog extraction, tagging, dual-platform builds, and artifact attachment
- CONTRIBUTING.md, bug report and feature request issue templates
- Dependabot for automated GitHub Actions updates
- CHANGELOG.md following Keep a Changelog format

### Removed
- FibonacciCommandExecutor (too complex for a starter template)
- whoami command and ServerLoadEvent examples
