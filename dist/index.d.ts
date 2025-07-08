export declare const getItem: (key: string) => Promise<string | null>;
export declare const setItem: (key: string, value: string) => Promise<void>;
export declare const getAllItem: () => Promise<Record<string, string>>;
export declare const deleteItem: (key: string) => Promise<void>;
