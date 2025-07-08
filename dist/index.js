import RnwSecureStorage from './NativeRnwSecureStorage';
export const getItem = async (key) => RnwSecureStorage.get(key);
export const setItem = async (key, value) => RnwSecureStorage.set(key, value);
export const deleteItem = async (key) => RnwSecureStorage.delete(key);
