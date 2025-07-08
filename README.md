# rnw-secure-storage

A simple Windows-only React Native TurboModule for secure, OS-managed encryption storage using the Windows Credential Locker (`PasswordVault`).

## Features

- Automatic overwrite on duplicate keys  
- Data is automatically purged when the app is uninstalled  
- Optional Windows Hello (biometric/PIN) integration  

## API

- `getItem(key: string): Promise<string | null>`  
- `setItem(key: string, value: string): Promise<void>`  
- `deleteItem(key: string): Promise<void>`  

## Installation

```bash
npm install rnw-secure-storage
```

## Usage
```ts
import * as rnwSS from 'rnw-secure-storage';

async function example() {
  await rnwSS.setItem('targetKey', 'abc123');
  const targetValue = await rnwSS.getItem('targetKey'); // "abc123" 
  await rnwSS.deleteItem('targetKey');
}
```
