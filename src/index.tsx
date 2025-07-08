import RnwSecureStorage from './NativeRnwSecureStorage';

export const getItem = async (key: string): Promise<string | null> => RnwSecureStorage.get(key);
export const setItem = async (
  key: string, 
  value: string,
): Promise<void> => RnwSecureStorage.set(key, value);
export const getAllItem = async (): Promise<Record<string, string>> => RnwSecureStorage.getAll();
export const deleteItem = async (key: string): Promise<void> => RnwSecureStorage.delete(key);
